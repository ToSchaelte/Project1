using System;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Windows.Forms;
using WindowsFormsApp20240828.Repositories;

namespace WindowsFormsApp20240828
{
    public partial class MainForm : Form
    {
        private readonly DbHandler _dbHandler = new DbHandler();

        private bool _appClosing;

        private ParticipantRepository ParticipantRepository => _dbHandler.Repositories.ParticipantRepository;

        public MainForm()
        {
            InitializeComponent();
            StaticProperties.DefaultBackColor = StaticProperties.Config.BackColor = BackColor;
            StaticProperties.DefaultForeColor = StaticProperties.Config.ForeColor = ForeColor;
            StaticProperties.Config.Font = Font;

        }

        private void OnLoad(object sender, EventArgs e)
        {
            if (!_dbHandler.OpenSQLiteConnection())
            {
                MessageBox.Show(Strings.TheDatabaseFileCouldNotBeOpened, Strings.DatabaseError,
                    MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                Application.Exit();
                return;
            }

            if (File.Exists(StaticProperties.ConfigPath)) StaticProperties.Config = (Configuration)XmlHelper.DeserializeXml<Configuration>(StaticProperties.ConfigPath);

            ResetVisualizaiton();
            DetailViewDialog.Instance.FormClosing += DetailViewDialog_FormClosing;
        }

        private void FillSchoolComboBox()
        {
            schoolComboBox.Items.Clear();
            schoolComboBox.Items.AddRange(StaticProperties.Schools.Keys.OrderBy(s => s).ToArray());
            schoolComboBox.SelectedIndex = 0;
        }

        private void FillProgrammingLanguagesCheckedListBox()
        {
            programmingLanguagesCheckedListBox.Items.Clear();
            programmingLanguagesCheckedListBox.Items.AddRange(StaticProperties.ProgrammingLanguages.OrderBy(s => s).ToArray());
        }

        private void ResetVisualizaiton()
        {
            SetColors();
            SetFont(this, StaticProperties.Config.Font);
            FillSchoolComboBox();
            FillProgrammingLanguagesCheckedListBox();
            FillParticipantListBox();
            firstNameTextBox.Text = string.Empty;
            lastNameTextBox.Text = string.Empty;
            schoolstartDateTimePicker.Value = DateTime.Now;
            foreach (var item in experienceGroupBox.Controls.Cast<Control>().Where(c => c is RadioButton).Cast<RadioButton>())
            {
                item.Checked = false;
            }
        }

        private void SetColors()
        {
            SetBackColor(this, StaticProperties.Config.BackColor);
            SetForeColor(this, StaticProperties.Config.ForeColor);
        }

        private void schoolComboBox_OnSelectedIndexChanged(object sender, EventArgs e)
        {
            var image = StaticProperties.Schools.FirstOrDefault(s => s.Key == schoolComboBox.SelectedItem.ToString()).Value;
            if (image is null) return;
            schoolPictureBox.Image = image;
        }

        private void addButton_OnClick(object sender, EventArgs e)
        {
            Enums.Experience? exp = null;
            if (lessThanOneYearRadioButton.Checked) exp = Enums.Experience.LessThanOne;
            else if (oneToFourYearsRadioButton.Checked) exp = Enums.Experience.OneToFour;
            else if (fiveToNineYearsRadioButton.Checked) exp = Enums.Experience.FiveToNine;
            else if (moreThanTenYearsRadioButton.Checked) exp = Enums.Experience.MoreThanTen;

            if (string.IsNullOrEmpty(firstNameTextBox.Text) || string.IsNullOrEmpty(firstNameTextBox.Text) || exp is null)
            {
                MessageBox.Show($"{Strings.YourDataIsInvalid_period} {Strings.TheEntryWillNotBeSaved_period}", Strings.InvalidData);
                return;
            }

            if (ParticipantRepository.Participants.Any(p => p.FirstName == firstNameTextBox.Text && p.LastName == lastNameTextBox.Text))
            {
                MessageBox.Show($"{Strings.AParticipantWithThisNameAlreadyExists_period} {Strings.TheEntryWillNotBeSaved_period}", Strings.TheEntryAlreadyExists);
                return;
            }

            ParticipantRepository.Participants.Add(new Participant(
                firstNameTextBox.Text, lastNameTextBox.Text,
                schoolComboBox.SelectedItem.ToString(), schoolstartDateTimePicker.Value,
                (Enums.Experience)exp, programmingLanguagesCheckedListBox.CheckedItems.Cast<string>().ToList()));
            ParticipantRepository.Update();
            FillParticipantListBox();
        }

        private void FillParticipantListBox()
        {
            allParticipantsListBox.Items.Clear();
            allParticipantsListBox.Items.AddRange(ParticipantRepository.Participants.ToArray());
        }

        private void zuruecksetzenButton_Click(object sender, EventArgs e)
        {
            if (DialogResult.Yes != MessageBox.Show(Strings.DoYouWantToDeleteAllData_question, Strings.USureAboutThat_question, MessageBoxButtons.YesNo)) return;
            ResetVisualizaiton();
        }

        private void deleteSelectedParticipants_Click(object sender, EventArgs e)
        {
            if (allParticipantsListBox.SelectedItems.Count <= 0) return;
            if (DialogResult.Yes == MessageBox.Show($"{Strings.DoYouReallyWantToDeleteTheFollowingParticipants_question}" +
                                                    $"\n{string.Join(", ", allParticipantsListBox.SelectedItems.Cast<object>().Select(p => p.ToString()))}",
                                                    Strings.DeleteParticipants, MessageBoxButtons.YesNo))
            {
                foreach (var item in allParticipantsListBox.SelectedItems)
                {
                    ParticipantRepository.Participants.Remove(ParticipantRepository.Participants.First(p => p.ToString() == item.ToString()));
                }
                ParticipantRepository.Update();
                FillParticipantListBox();
            }
        }

        private void SetFont(Font font)
        {
            SetFont(this, StaticProperties.Config.Font = font);
            SetFont(DetailViewDialog.Instance, StaticProperties.Config.Font);
        }

        private void SetFont(Control control, Font font)
        {
            control.Font = font;
            foreach (var c in control.Controls.Cast<Control>()) SetFont(c, font);
        }

        private void SetBackColor(Color color)
        {
            SetBackColor(this, StaticProperties.Config.BackColor = color);
            SetBackColor(DetailViewDialog.Instance, StaticProperties.Config.BackColor);
        }

        private void SetBackColor(Control control, Color color)
        {
            control.BackColor = color;
            foreach (var c in control.Controls.Cast<Control>().Where(c => c is Form
            || c is GroupBox || c is ListBox || c is ToolStrip)) SetBackColor(c, color);
        }

        private void SetForeColor(Color color)
        {
            SetForeColor(this, StaticProperties.Config.ForeColor = color);
            SetForeColor(DetailViewDialog.Instance, StaticProperties.Config.ForeColor);
        }

        private void SetForeColor(Control control, Color color)
        {
            control.ForeColor = color;
            if (control is DateTimePicker dtp)  dtp.CalendarForeColor = dtp.CalendarTitleForeColor = dtp.CalendarTrailingForeColor = color;
            foreach (var c in control.Controls.Cast<Control>()) SetForeColor(c, color);
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void schriftartToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var fd = new FontDialog { Font = Font };
            if (fd.ShowDialog() == DialogResult.OK) SetFont(fd.Font);
        }

        private void exportierenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var sfd = new SaveFileDialog();
            sfd.FileName = StaticProperties.ParticipantsFilename;
            sfd.Filter = "Xml File|*.xml";
            sfd.Title = "Save Participants";
            sfd.CheckPathExists = true;
            if (sfd.ShowDialog() != DialogResult.OK
                || string.IsNullOrWhiteSpace(sfd.FileName)) return;
            XmlHelper.SerializeXml(ParticipantRepository.Participants.ToList(), (FileStream)sfd.OpenFile());
        }

        private void hintergrundfarbeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var cd = new ColorDialog { Color = BackColor };
            if (cd.ShowDialog() == DialogResult.OK) SetBackColor(cd.Color);
        }

        private void schriftfarbeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var cd = new ColorDialog { Color = ForeColor };
            if (cd.ShowDialog() == DialogResult.OK) SetForeColor(cd.Color);
        }

        private void enterBommertModeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Credits go to Jakob Bommert
            SetForeColor(Color.FromArgb(255, 214, 128));
            SetBackColor(Color.Yellow);
            SetFont(new Font(FontFamily.Families.First(f => f.Name.Contains("Comic Sans")), 10, FontStyle.Italic));
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            XmlHelper.SerializeXml(StaticProperties.Config, StaticProperties.ConfigPath);
            _appClosing = true;
            DetailViewDialog.Instance.Close();
            Application.Exit();
        }

        private void zuDefaultToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SetForeColor(StaticProperties.DefaultForeColor);
            SetBackColor(StaticProperties.DefaultBackColor);
            SetFont(StaticProperties.DefaultFont);
        }

        private void detailsButton_Click(object sender, EventArgs e)
        {
            if (DetailViewDialog.Instance.Visible)
            {
                DetailViewDialog.Instance.Focus();
                return;
            }
            DetailViewDialog.Instance.ParticipantRepository = ParticipantRepository;
            DetailViewDialog.Instance.Show();
        }

        private void DetailViewDialog_FormClosing(object sender, FormClosingEventArgs e)
        {
            e.Cancel = !_appClosing;
        }
    }
}
