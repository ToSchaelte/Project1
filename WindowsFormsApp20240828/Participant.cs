using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace WindowsFormsApp20240828
{
    public class Participant
    {
        [XmlAttribute]
        public string FirstName { get; set; } = string.Empty;

        [XmlAttribute]
        public string LastName { get; set; } = string.Empty;

        [XmlAttribute]
        public string School { get; set; } = string.Empty;

        public DateTime SchoolEntry { get; set; } = DateTime.Now;

        [XmlAttribute]
        public Enums.Experience Experience { get; set; }

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

        public override string ToString()
        {
            return $"{FirstName} {LastName}";
        }
    }
}
