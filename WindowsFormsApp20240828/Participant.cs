using System;
using System.Collections.Generic;
using System.Data;
using System.Xml.Serialization;

namespace WindowsFormsApp20240828
{
    public class Participant
    {
        [XmlAttribute]
        public int Id { get; set; } = 0;

        [XmlAttribute]
        public string FirstName { get; set; } = string.Empty;

        [XmlAttribute]
        public string LastName { get; set; } = string.Empty;

        [XmlAttribute]
        public string School { get; set; } = string.Empty;

        [XmlAttribute("DateOfSchoolEntry")]
        public DateTime SchoolEntry { get; set; } = DateTime.Now;

        [XmlAttribute("ExperienceInYears")]
        public Enums.Experience Experience { get; set; }

        [XmlArray("ProgrammingLanguages")]
        [XmlArrayItem("Language")]
        public List<string> ProgrammingLanguages { get; set; } = new List<string>();

        public Participant()
        { }

        public Participant(string firstName, string lastName, string school, DateTime schoolEntry, Enums.Experience experience, List<string> programmingLanguages)
        {
            FirstName = firstName;
            LastName = lastName;
            School = school;
            SchoolEntry = schoolEntry;
            Experience = experience;
            ProgrammingLanguages = programmingLanguages;
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
