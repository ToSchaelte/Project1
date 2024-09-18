using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Data;
using System.Runtime.CompilerServices;
using System.Xml.Serialization;
using WindowsFormsApp20240828.Helpers;

namespace WindowsFormsApp20240828
{
    public class Participant : INotifyPropertyChanged
    {

        public event PropertyChangedEventHandler PropertyChanged;

        protected virtual void OnPropertyChanged([CallerMemberName] string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        private int _id = -1;
        [XmlAttribute]
        public int Id
        {
            get => _id;
            set => PropertyHelper.SetAndNotify(ref _id,
                value, nameof(Id), OnPropertyChanged);
        }

        private string _firstName = string.Empty;
        [XmlAttribute]
        public string FirstName
        {
            get => _firstName;
            set => PropertyHelper.SetAndNotify(ref _firstName,
                value, nameof(FirstName), OnPropertyChanged);
        }

        private string _lastName = string.Empty;
        [XmlAttribute]
        public string LastName
        {
            get => _lastName;
            set => PropertyHelper.SetAndNotify(ref _lastName,
                value, nameof(LastName), OnPropertyChanged);
        }

        private string _school = string.Empty;
        [XmlAttribute]
        public string School
        {
            get => _school;
            set => PropertyHelper.SetAndNotify(ref _school,
                value, nameof(School), OnPropertyChanged);
        }

        private DateTime _schoolEntry = DateTime.UtcNow;
        [XmlAttribute("DateOfSchoolEntry")]
        public DateTime SchoolEntry
        {
            get => _schoolEntry;
            set => PropertyHelper.SetAndNotify(ref _schoolEntry,
                value, nameof(SchoolEntry), OnPropertyChanged);
        }

        private Enums.Experience _experience = 0;
        [XmlAttribute("ExperienceInYears")]
        public Enums.Experience Experience
        {
            get => _experience;
            set => PropertyHelper.SetAndNotify(ref _experience,
                value, nameof(Experience), OnPropertyChanged);
        }

        private ObservableCollection<string> _programmingLanguages = new ObservableCollection<string>();
        [XmlArray("ProgrammingLanguages")]
        [XmlArrayItem("Language")]
        public ObservableCollection<string> ProgrammingLanguages
        {
            get => _programmingLanguages;
            set => PropertyHelper.SetAndNotify(ref _programmingLanguages,
                value, nameof(ProgrammingLanguages), OnPropertyChanged);
        }

        public static Participant Empty => new Participant();

        public Participant()
        { }

        public Participant(string firstName, string lastName, string school, DateTime schoolEntry, Enums.Experience experience, List<string> programmingLanguages)
        {
            FirstName = firstName;
            LastName = lastName;
            School = school;
            SchoolEntry = schoolEntry;
            Experience = experience;
            ProgrammingLanguages = new ObservableCollection<string>(programmingLanguages);
            ProgrammingLanguages.CollectionChanged += (sender, e) =>
            {
                PropertyHelper.SetAndNotify(ref _programmingLanguages, ProgrammingLanguages, nameof(ProgrammingLanguages), OnPropertyChanged);
            };
        }

        public static Participant FromReader(IDataReader reader)
        {
            try
            {
                var dbItemCounter = 0;
                var temp = new Participant
                {
                    Id = reader.GetInt32(dbItemCounter++),
                    LastName = reader.GetString(dbItemCounter++),
                    FirstName = reader.GetString(dbItemCounter++),
                    School = reader.GetString(dbItemCounter++),
                    SchoolEntry = DateTime.Parse(reader.GetString(dbItemCounter++)),
                    Experience = (Enums.Experience)reader.GetInt32(dbItemCounter++)
                };
                temp.ProgrammingLanguages.Clear();
                foreach (var language in StaticProperties.ProgrammingLanguages)
                {
                    if (!reader.GetBoolean(dbItemCounter++)) continue;
                    temp.ProgrammingLanguages.Add(language);
                }
                return temp;
            }
            catch
            {
                return null;
            }
        }

        public override string ToString()
        {
            return $"{FirstName} {LastName}";
        }
    }
}
