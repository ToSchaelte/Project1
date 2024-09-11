using System;
using System.Data.Entity.Migrations.Design;
using System.Windows.Forms;
using WindowsFormsApp20240828.Repositories;

namespace WindowsFormsApp20240828
{
    public partial class DetailViewDialog : Form
    {
        private ParticipantRepository _participantRepository;

        public ParticipantRepository ParticipantRepository
        {
            get => _participantRepository;
            set
            {
                if (_participantRepository == value) return;
                _participantRepository = value;
                FillDataTable();
                _participantRepository.Participants.CollectionChanged += Participants_CollectionChanged;
            }
        }

        private DetailViewDialog()
        {
            InitializeComponent();
        }

        private readonly static DetailViewDialog _instance = new DetailViewDialog();
        public static DetailViewDialog Instance => _instance;

        private void Participants_CollectionChanged(object sender, System.Collections.Specialized.NotifyCollectionChangedEventArgs e)
        {
            FillDataTable();
        }

        private void FillDataTable()
        {
            detailsDataGridView.Rows.Clear();

            foreach (var item in ParticipantRepository.Participants)
            {
                detailsDataGridView.Rows.Add(new object[] { item.Id, item.LastName, item.FirstName,
                    item.School, item.SchoolEntry.ToShortDateString(), item.Experience,
                    string.Join(", ", item.ProgrammingLanguages) });
            }
        }

        private void DetailViewDialog_FormClosing(object sender, FormClosingEventArgs e)
        {
            e.Cancel = true;
            Visible = false;
        }
    }
}
