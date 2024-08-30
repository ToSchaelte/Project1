using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp20240828
{
    public partial class Form1 : Form
    {
        private readonly Dictionary<string, Image> schools = new Dictionary<string, Image>
        {
            { "BK am Haspel", Images.amHaspel },
            { "BK Niederberg", Images.Niederberg },
            { "BK Technik Remscheid", Images.Remscheid },
            { "Heinz-Nixdorf-BK", Images.HeinzNixdorf },
            { "RW BK Essen", Images.RWEssen },
            { "BK Wesel", Images.Wesel },
            { "BK Siegen", Images.Siegen },
            { "BK Witten", Images.Witten },
            { "BK Solingen", Images.Solingen },
            { "Heinrich-Hertz-BK Bonn", Images.HeinrichHertzBonn },
            { "Heinrich-Hertz-BK Ddorf", Images.HeinrichHertzDdorf },
            { "Bertholt-Brecht-BK", Images.BertholdBrecht },
            { "BK Duisburg-Mitte", Images.Duisburg },
            { "Erich-Gutenberg-BK", Images.ErichGutenberg },
            { "BK Geschwister-Scholl", Images.Leverkusen },
            { "BK Oberberg", Images.Oberberg },
            { "Lippe-BK", Images.Lippe },
            { "BK Hilden", Images.Hilden }
        };

        private readonly List<string> programmingLanguages = new List<string>
        {
                "Cobol",
                "Basic",
                "C",
                "C++",
                "Delphi",
                "Java",
                "C#"
        };

        private readonly List<Participant> _participants = new List<Participant>();

        private string XmlPath => Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Desktop), "Participants.xml");

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            _participants.Clear();
            if(File.Exists(XmlPath)) _participants.AddRange((List<Participant>)XmlHelper.DeserializeXml<List<Participant>>(XmlPath));
            
            ResetVisualizaiton();
            fontsToolStripComboBox.Items.Clear();
            fontsToolStripComboBox.Items.AddRange(FontFamily.Families.Select(ff => ff.Name).ToArray());
            fontsToolStripComboBox.SelectedItem = "Arial";
        }

        private void FillSchulnamen()
        {
            schulnameComboBox.Items.Clear();
            schulnameComboBox.Items.AddRange(schools.Keys.OrderBy(s => s).ToArray());
            schulnameComboBox.SelectedIndex = 0;
        }

        private void FillProgrammiersprachen()
        {
            programmiersprachenCheckedListBox.Items.Clear();
            programmiersprachenCheckedListBox.Items.AddRange(programmingLanguages.OrderBy(s => s).ToArray());
        }

        private void ResetVisualizaiton()
        {
            FillSchulnamen();
            FillProgrammiersprachen();
            FillParticipantListBox();
            vornameTextBox.Text = string.Empty;
            nachnameTextBox.Text = string.Empty;
            schulstartDateTimePicker.Value = DateTime.Now;
            foreach (var item in erfahrungenGroupBox.Controls)
            {
                if (item is RadioButton rb) rb.Checked = false;
            }
        }

        private void schulnameComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            var image = schools.FirstOrDefault(s => s.Key == schulnameComboBox.SelectedItem.ToString()).Value;
            if (image is null) return;
            schoolPictureBox.Image = image;
        }

        private void hinzufuegenButton_Click(object sender, EventArgs e)
        {
            Enums.Experience? exp = null;
            if (unterEinJahrRadioButton.Checked) exp = Enums.Experience.LessThanOne;
            else if (einBisVierJahreRadioButton.Checked) exp = Enums.Experience.OneToFour;
            else if (fuenfBisNeunJahreRadioButton.Checked) exp = Enums.Experience.FiveToNine;
            else if (mehrAlsZehnJahreRadioButton.Checked) exp = Enums.Experience.MoreThanTen;

            if (string.IsNullOrEmpty(vornameTextBox.Text) || string.IsNullOrEmpty(vornameTextBox.Text) || exp is null)
            {
                MessageBox.Show("Your data is invalid. The entry will not be saved.", "Invalid data");
                return;
            }

            if (_participants.Any(p => p.FirstName == vornameTextBox.Text && p.LastName == nachnameTextBox.Text))
            {
                MessageBox.Show("A participant with this name already exists. The entry will not be saved.", "Already exists");
                return;
            }

            _participants.Add(new Participant(
                vornameTextBox.Text, nachnameTextBox.Text,
                schulnameComboBox.SelectedItem.ToString(), schulstartDateTimePicker.Value,
                (Enums.Experience)exp, programmiersprachenCheckedListBox.CheckedItems.Cast<string>().ToList()));
            XmlHelper.SerializeXml(_participants, XmlPath);
            FillParticipantListBox();
        }

        private void FillParticipantListBox()
        {
            allParticipantsListBox.Items.Clear();
            allParticipantsListBox.Items.AddRange(_participants.ToArray());
        }

        private void zuruecksetzenButton_Click(object sender, EventArgs e)
        {
            if (DialogResult.Yes != MessageBox.Show("Möchten Sie wirklich alle eingegebenen Daten leeren?", "U sure about that?", MessageBoxButtons.YesNo)) return;
            ResetVisualizaiton();
        }

        private void deleteSelectedParticipants_Click(object sender, EventArgs e)
        {
            if (allParticipantsListBox.SelectedItems.Count <= 0) return;
            if (DialogResult.Yes == MessageBox.Show($"Möchten Sie wirklich die folgenden Teilnehmer*innen löschen?\n{string.Join(", ", allParticipantsListBox.SelectedItems.Cast<object>().Select(p => p.ToString()))}", "Teilnehmer*innen löschen", MessageBoxButtons.YesNo))
            {
                foreach (var item in allParticipantsListBox.SelectedItems)
                {
                    _participants.Remove(_participants.First(p => p.ToString() == item.ToString()));
                }
                XmlHelper.SerializeXml(_participants, XmlPath);
                FillParticipantListBox();
            }
        }

        private void fontsToolStripComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (fontsToolStripComboBox.SelectedIndex < 0) return;
            SetFont(this, FontFamily.Families[fontsToolStripComboBox.SelectedIndex]);
        }

        private void SetFont(Control control, FontFamily fontFamily)
        {
            control.Font = new Font(fontFamily, control.Font.Size, control.Font.Style);
            foreach (var c in control.Controls.Cast<Control>()) SetFont(c, fontFamily);
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
