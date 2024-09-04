namespace WindowsFormsApp20240828
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.firstNameLabel = new System.Windows.Forms.Label();
            this.lastNameLabel = new System.Windows.Forms.Label();
            this.firstNameTextBox = new System.Windows.Forms.TextBox();
            this.schoolLabel = new System.Windows.Forms.Label();
            this.schoolComboBox = new System.Windows.Forms.ComboBox();
            this.lastNameTextBox = new System.Windows.Forms.TextBox();
            this.schoolstartLabel = new System.Windows.Forms.Label();
            this.experienceGroupBox = new System.Windows.Forms.GroupBox();
            this.moreThanTenYearsRadioButton = new System.Windows.Forms.RadioButton();
            this.fiveToNineYearsRadioButton = new System.Windows.Forms.RadioButton();
            this.oneToFourYearsRadioButton = new System.Windows.Forms.RadioButton();
            this.lessThanOneYearRadioButton = new System.Windows.Forms.RadioButton();
            this.programmingLanguagesCheckedListBox = new System.Windows.Forms.CheckedListBox();
            this.resetButton = new System.Windows.Forms.Button();
            this.addButton = new System.Windows.Forms.Button();
            this.schoolstartDateTimePicker = new System.Windows.Forms.DateTimePicker();
            this.schoolPictureBox = new System.Windows.Forms.PictureBox();
            this.allParticipantsListBox = new System.Windows.Forms.ListBox();
            this.deleteSelectedParticipants = new System.Windows.Forms.Button();
            this.mainMenuStrip = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.fontToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.backgroundColorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.foreColorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.activateBommertModeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.resetToDefaultToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.experienceGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.schoolPictureBox)).BeginInit();
            this.mainMenuStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // firstNameLabel
            // 
            resources.ApplyResources(this.firstNameLabel, "firstNameLabel");
            this.firstNameLabel.Name = "firstNameLabel";
            // 
            // lastNameLabel
            // 
            resources.ApplyResources(this.lastNameLabel, "lastNameLabel");
            this.lastNameLabel.Name = "lastNameLabel";
            // 
            // firstNameTextBox
            // 
            resources.ApplyResources(this.firstNameTextBox, "firstNameTextBox");
            this.firstNameTextBox.Name = "firstNameTextBox";
            // 
            // schoolLabel
            // 
            resources.ApplyResources(this.schoolLabel, "schoolLabel");
            this.schoolLabel.Name = "schoolLabel";
            // 
            // schoolComboBox
            // 
            this.schoolComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.schoolComboBox.FormattingEnabled = true;
            resources.ApplyResources(this.schoolComboBox, "schoolComboBox");
            this.schoolComboBox.Name = "schoolComboBox";
            this.schoolComboBox.SelectedIndexChanged += new System.EventHandler(this.schoolComboBox_OnSelectedIndexChanged);
            // 
            // lastNameTextBox
            // 
            resources.ApplyResources(this.lastNameTextBox, "lastNameTextBox");
            this.lastNameTextBox.Name = "lastNameTextBox";
            // 
            // schoolstartLabel
            // 
            resources.ApplyResources(this.schoolstartLabel, "schoolstartLabel");
            this.schoolstartLabel.Name = "schoolstartLabel";
            // 
            // experienceGroupBox
            // 
            this.experienceGroupBox.Controls.Add(this.moreThanTenYearsRadioButton);
            this.experienceGroupBox.Controls.Add(this.fiveToNineYearsRadioButton);
            this.experienceGroupBox.Controls.Add(this.oneToFourYearsRadioButton);
            this.experienceGroupBox.Controls.Add(this.lessThanOneYearRadioButton);
            resources.ApplyResources(this.experienceGroupBox, "experienceGroupBox");
            this.experienceGroupBox.Name = "experienceGroupBox";
            this.experienceGroupBox.TabStop = false;
            // 
            // moreThanTenYearsRadioButton
            // 
            resources.ApplyResources(this.moreThanTenYearsRadioButton, "moreThanTenYearsRadioButton");
            this.moreThanTenYearsRadioButton.Name = "moreThanTenYearsRadioButton";
            this.moreThanTenYearsRadioButton.TabStop = true;
            this.moreThanTenYearsRadioButton.UseVisualStyleBackColor = true;
            // 
            // fiveToNineYearsRadioButton
            // 
            resources.ApplyResources(this.fiveToNineYearsRadioButton, "fiveToNineYearsRadioButton");
            this.fiveToNineYearsRadioButton.Name = "fiveToNineYearsRadioButton";
            this.fiveToNineYearsRadioButton.TabStop = true;
            this.fiveToNineYearsRadioButton.UseVisualStyleBackColor = true;
            // 
            // oneToFourYearsRadioButton
            // 
            resources.ApplyResources(this.oneToFourYearsRadioButton, "oneToFourYearsRadioButton");
            this.oneToFourYearsRadioButton.Name = "oneToFourYearsRadioButton";
            this.oneToFourYearsRadioButton.TabStop = true;
            this.oneToFourYearsRadioButton.UseVisualStyleBackColor = true;
            // 
            // lessThanOneYearRadioButton
            // 
            resources.ApplyResources(this.lessThanOneYearRadioButton, "lessThanOneYearRadioButton");
            this.lessThanOneYearRadioButton.Name = "lessThanOneYearRadioButton";
            this.lessThanOneYearRadioButton.TabStop = true;
            this.lessThanOneYearRadioButton.UseVisualStyleBackColor = true;
            // 
            // programmingLanguagesCheckedListBox
            // 
            this.programmingLanguagesCheckedListBox.CheckOnClick = true;
            this.programmingLanguagesCheckedListBox.FormattingEnabled = true;
            resources.ApplyResources(this.programmingLanguagesCheckedListBox, "programmingLanguagesCheckedListBox");
            this.programmingLanguagesCheckedListBox.Name = "programmingLanguagesCheckedListBox";
            // 
            // resetButton
            // 
            resources.ApplyResources(this.resetButton, "resetButton");
            this.resetButton.Name = "resetButton";
            this.resetButton.UseVisualStyleBackColor = true;
            this.resetButton.Click += new System.EventHandler(this.zuruecksetzenButton_Click);
            // 
            // addButton
            // 
            resources.ApplyResources(this.addButton, "addButton");
            this.addButton.Name = "addButton";
            this.addButton.UseVisualStyleBackColor = true;
            this.addButton.Click += new System.EventHandler(this.addButton_OnClick);
            // 
            // schoolstartDateTimePicker
            // 
            resources.ApplyResources(this.schoolstartDateTimePicker, "schoolstartDateTimePicker");
            this.schoolstartDateTimePicker.Name = "schoolstartDateTimePicker";
            // 
            // schoolPictureBox
            // 
            resources.ApplyResources(this.schoolPictureBox, "schoolPictureBox");
            this.schoolPictureBox.Name = "schoolPictureBox";
            this.schoolPictureBox.TabStop = false;
            // 
            // allParticipantsListBox
            // 
            this.allParticipantsListBox.FormattingEnabled = true;
            resources.ApplyResources(this.allParticipantsListBox, "allParticipantsListBox");
            this.allParticipantsListBox.Name = "allParticipantsListBox";
            this.allParticipantsListBox.SelectionMode = System.Windows.Forms.SelectionMode.MultiExtended;
            // 
            // deleteSelectedParticipants
            // 
            resources.ApplyResources(this.deleteSelectedParticipants, "deleteSelectedParticipants");
            this.deleteSelectedParticipants.Name = "deleteSelectedParticipants";
            this.deleteSelectedParticipants.UseVisualStyleBackColor = true;
            this.deleteSelectedParticipants.Click += new System.EventHandler(this.deleteSelectedParticipants_Click);
            // 
            // mainMenuStrip
            // 
            this.mainMenuStrip.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.mainMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.viewToolStripMenuItem});
            resources.ApplyResources(this.mainMenuStrip, "mainMenuStrip");
            this.mainMenuStrip.Name = "mainMenuStrip";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exportToolStripMenuItem,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            resources.ApplyResources(this.fileToolStripMenuItem, "fileToolStripMenuItem");
            // 
            // exportToolStripMenuItem
            // 
            this.exportToolStripMenuItem.Name = "exportToolStripMenuItem";
            resources.ApplyResources(this.exportToolStripMenuItem, "exportToolStripMenuItem");
            this.exportToolStripMenuItem.Click += new System.EventHandler(this.exportierenToolStripMenuItem_Click);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            resources.ApplyResources(this.exitToolStripMenuItem, "exitToolStripMenuItem");
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // viewToolStripMenuItem
            // 
            this.viewToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fontToolStripMenuItem,
            this.backgroundColorToolStripMenuItem,
            this.foreColorToolStripMenuItem,
            this.activateBommertModeToolStripMenuItem,
            this.resetToDefaultToolStripMenuItem});
            this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
            resources.ApplyResources(this.viewToolStripMenuItem, "viewToolStripMenuItem");
            // 
            // fontToolStripMenuItem
            // 
            this.fontToolStripMenuItem.Name = "fontToolStripMenuItem";
            resources.ApplyResources(this.fontToolStripMenuItem, "fontToolStripMenuItem");
            this.fontToolStripMenuItem.Click += new System.EventHandler(this.schriftartToolStripMenuItem_Click);
            // 
            // backgroundColorToolStripMenuItem
            // 
            this.backgroundColorToolStripMenuItem.Name = "backgroundColorToolStripMenuItem";
            resources.ApplyResources(this.backgroundColorToolStripMenuItem, "backgroundColorToolStripMenuItem");
            this.backgroundColorToolStripMenuItem.Click += new System.EventHandler(this.hintergrundfarbeToolStripMenuItem_Click);
            // 
            // foreColorToolStripMenuItem
            // 
            this.foreColorToolStripMenuItem.Name = "foreColorToolStripMenuItem";
            resources.ApplyResources(this.foreColorToolStripMenuItem, "foreColorToolStripMenuItem");
            this.foreColorToolStripMenuItem.Click += new System.EventHandler(this.schriftfarbeToolStripMenuItem_Click);
            // 
            // activateBommertModeToolStripMenuItem
            // 
            this.activateBommertModeToolStripMenuItem.Name = "activateBommertModeToolStripMenuItem";
            resources.ApplyResources(this.activateBommertModeToolStripMenuItem, "activateBommertModeToolStripMenuItem");
            this.activateBommertModeToolStripMenuItem.Click += new System.EventHandler(this.enterBommertModeToolStripMenuItem_Click);
            // 
            // resetToDefaultToolStripMenuItem
            // 
            this.resetToDefaultToolStripMenuItem.Name = "resetToDefaultToolStripMenuItem";
            resources.ApplyResources(this.resetToDefaultToolStripMenuItem, "resetToDefaultToolStripMenuItem");
            this.resetToDefaultToolStripMenuItem.Click += new System.EventHandler(this.zuDefaultToolStripMenuItem_Click);
            // 
            // MainForm
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.deleteSelectedParticipants);
            this.Controls.Add(this.allParticipantsListBox);
            this.Controls.Add(this.schoolPictureBox);
            this.Controls.Add(this.schoolstartDateTimePicker);
            this.Controls.Add(this.addButton);
            this.Controls.Add(this.resetButton);
            this.Controls.Add(this.programmingLanguagesCheckedListBox);
            this.Controls.Add(this.experienceGroupBox);
            this.Controls.Add(this.schoolstartLabel);
            this.Controls.Add(this.lastNameTextBox);
            this.Controls.Add(this.schoolComboBox);
            this.Controls.Add(this.schoolLabel);
            this.Controls.Add(this.firstNameTextBox);
            this.Controls.Add(this.lastNameLabel);
            this.Controls.Add(this.firstNameLabel);
            this.Controls.Add(this.mainMenuStrip);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.mainMenuStrip;
            this.MaximizeBox = false;
            this.Name = "MainForm";
            this.ShowIcon = false;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.OnLoad);
            this.experienceGroupBox.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.schoolPictureBox)).EndInit();
            this.mainMenuStrip.ResumeLayout(false);
            this.mainMenuStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label firstNameLabel;
        private System.Windows.Forms.Label lastNameLabel;
        private System.Windows.Forms.TextBox firstNameTextBox;
        private System.Windows.Forms.Label schoolLabel;
        private System.Windows.Forms.ComboBox schoolComboBox;
        private System.Windows.Forms.TextBox lastNameTextBox;
        private System.Windows.Forms.Label schoolstartLabel;
        private System.Windows.Forms.GroupBox experienceGroupBox;
        private System.Windows.Forms.RadioButton lessThanOneYearRadioButton;
        private System.Windows.Forms.RadioButton moreThanTenYearsRadioButton;
        private System.Windows.Forms.RadioButton fiveToNineYearsRadioButton;
        private System.Windows.Forms.RadioButton oneToFourYearsRadioButton;
        private System.Windows.Forms.CheckedListBox programmingLanguagesCheckedListBox;
        private System.Windows.Forms.Button resetButton;
        private System.Windows.Forms.Button addButton;
        private System.Windows.Forms.DateTimePicker schoolstartDateTimePicker;
        private System.Windows.Forms.PictureBox schoolPictureBox;
        private System.Windows.Forms.ListBox allParticipantsListBox;
        private System.Windows.Forms.Button deleteSelectedParticipants;
        private System.Windows.Forms.MenuStrip mainMenuStrip;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem fontToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem backgroundColorToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem foreColorToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem activateBommertModeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem resetToDefaultToolStripMenuItem;
    }
}

