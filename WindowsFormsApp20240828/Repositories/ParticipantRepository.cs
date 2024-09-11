using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Data;
using System.Linq;

namespace WindowsFormsApp20240828.Repositories
{
    public class ParticipantRepository
    {
        private readonly List<Participant> _addedItems = new List<Participant>();
        private readonly List<Participant> _removedItems = new List<Participant>();

        private IDbConnection _dbConnection;
        public IDbConnection DbConnection
        {
            get => _dbConnection;
            set
            {
                if (_dbConnection == value) return;
                _dbConnection = value;
                ReloadDb();
            }
        }

        public ObservableCollection<Participant> Participants { get; } = new ObservableCollection<Participant>();

        public ParticipantRepository(IDbConnection dbConnection)
        {
            _dbConnection = dbConnection;
            Participants.CollectionChanged += Participants_CollectionChanged;
            ReloadDb();
        }

        public void ReloadDb()
        {
            Participants.CollectionChanged -= Participants_CollectionChanged;

            try
            {
                Participants.Clear();
                var dataCommand = _dbConnection.CreateCommand();
                dataCommand.Connection = _dbConnection;
                dataCommand.CommandText = "SELECT * FROM Teilnehmer";
                var reader = dataCommand.ExecuteReader();
                while (reader.Read())
                {
                    var temp = Participant.FromReader(reader);
                    if (temp is null) continue;
                    Participants.Add(temp);
                }
                reader.Close();
            }
            catch (Exception ex) { }

            Participants.CollectionChanged += Participants_CollectionChanged;
        }

        private void Participants_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
        {
            switch (e.Action)
            {
                case NotifyCollectionChangedAction.Add:
                    _addedItems.AddRange(e.NewItems.Cast<Participant>());
                    break;
                case NotifyCollectionChangedAction.Replace:
                    _removedItems.AddRange(e.OldItems.Cast<Participant>());
                    _addedItems.AddRange(e.NewItems.Cast<Participant>());
                    break;
                case NotifyCollectionChangedAction.Reset:
                case NotifyCollectionChangedAction.Remove:
                    _removedItems.AddRange(e.OldItems.Cast<Participant>());
                    break;
                case NotifyCollectionChangedAction.Move:
                    break;

            }
        }

        private void ClearTable()
        {
            try
            {
                var dataCommand = _dbConnection.CreateCommand();
                dataCommand.Connection = _dbConnection;
                dataCommand.CommandText = "DELETE FROM Teilnehmer;";
                dataCommand.ExecuteNonQuery();
            }
            catch { }
        }

        private void OnItemsAdded(IEnumerable<Participant> newItems)
        {
            foreach (var item in newItems)
            {
                for (var i = 1; true; i++)
                {
                    if (Participants.Any(p => p.Id == i)) continue;
                    item.Id = i;
                    break;
                }

                try
                {
                    var dataCommand = _dbConnection.CreateCommand();
                    dataCommand.Connection = _dbConnection;
                    dataCommand.CommandText = "INSERT INTO Teilnehmer " +
                        $"VALUES ({item.Id}, '{item.LastName}', '{item.FirstName}', '{item.School}', '{item.SchoolEntry.ToShortDateString()}', {(int)item.Experience}, {string.Join(", ", StaticProperties.ProgrammingLanguages.Select(l => Convert.ToInt16(item.ProgrammingLanguages.Contains(l))))});";
                    dataCommand.ExecuteNonQuery();
                }
                catch { }
            }
        }

        private void OnItemsRemoved(IEnumerable<Participant> oldItems)
        {
            foreach (var item in oldItems)
            {
                try
                {
                    var dataCommand = _dbConnection.CreateCommand();
                    dataCommand.Connection = _dbConnection;
                    dataCommand.CommandText = $"DELETE FROM Teilnehmer WHERE ID={item.Id};";
                    dataCommand.ExecuteNonQuery();
                }
                catch { }
            }
        }

        public void Update()
        {
            OnItemsRemoved(_removedItems);
            OnItemsAdded(_addedItems);
            _removedItems.Clear();
            _addedItems.Clear();
        }
    }
}
