namespace WindowsFormsApp20240828
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.vornameLabel = new System.Windows.Forms.Label();
            this.nachnameLabel = new System.Windows.Forms.Label();
            this.vornameTextBox = new System.Windows.Forms.TextBox();
            this.schuleLabel = new System.Windows.Forms.Label();
            this.schulnameComboBox = new System.Windows.Forms.ComboBox();
            this.nachnameTextBox = new System.Windows.Forms.TextBox();
            this.schulstartLabel = new System.Windows.Forms.Label();
            this.erfahrungenGroupBox = new System.Windows.Forms.GroupBox();
            this.mehrAlsZehnJahreRadioButton = new System.Windows.Forms.RadioButton();
            this.fuenfBisNeunJahreRadioButton = new System.Windows.Forms.RadioButton();
            this.einBisVierJahreRadioButton = new System.Windows.Forms.RadioButton();
            this.unterEinJahrRadioButton = new System.Windows.Forms.RadioButton();
            this.programmiersprachenCheckedListBox = new System.Windows.Forms.CheckedListBox();
            this.zuruecksetzenButton = new System.Windows.Forms.Button();
            this.hinzufuegenButton = new System.Windows.Forms.Button();
            this.schulstartDateTimePicker = new System.Windows.Forms.DateTimePicker();
            this.schoolPictureBox = new System.Windows.Forms.PictureBox();
            this.allParticipantsListBox = new System.Windows.Forms.ListBox();
            this.deleteSelectedParticipants = new System.Windows.Forms.Button();
            this.erfahrungenGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.schoolPictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // vornameLabel
            // 
            resources.ApplyResources(this.vornameLabel, "vornameLabel");
            this.vornameLabel.Name = "vornameLabel";
            // 
            // nachnameLabel
            // 
            resources.ApplyResources(this.nachnameLabel, "nachnameLabel");
            this.nachnameLabel.Name = "nachnameLabel";
            // 
            // vornameTextBox
            // 
            resources.ApplyResources(this.vornameTextBox, "vornameTextBox");
            this.vornameTextBox.Name = "vornameTextBox";
            // 
            // schuleLabel
            // 
            resources.ApplyResources(this.schuleLabel, "schuleLabel");
            this.schuleLabel.Name = "schuleLabel";
            // 
            // schulnameComboBox
            // 
            this.schulnameComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.schulnameComboBox.FormattingEnabled = true;
            resources.ApplyResources(this.schulnameComboBox, "schulnameComboBox");
            this.schulnameComboBox.Name = "schulnameComboBox";
            this.schulnameComboBox.SelectedIndexChanged += new System.EventHandler(this.schulnameComboBox_SelectedIndexChanged);
            // 
            // nachnameTextBox
            // 
            resources.ApplyResources(this.nachnameTextBox, "nachnameTextBox");
            this.nachnameTextBox.Name = "nachnameTextBox";
            // 
            // schulstartLabel
            // 
            resources.ApplyResources(this.schulstartLabel, "schulstartLabel");
            this.schulstartLabel.Name = "schulstartLabel";
            // 
            // erfahrungenGroupBox
            // 
            this.erfahrungenGroupBox.Controls.Add(this.mehrAlsZehnJahreRadioButton);
            this.erfahrungenGroupBox.Controls.Add(this.fuenfBisNeunJahreRadioButton);
            this.erfahrungenGroupBox.Controls.Add(this.einBisVierJahreRadioButton);
            this.erfahrungenGroupBox.Controls.Add(this.unterEinJahrRadioButton);
            resources.ApplyResources(this.erfahrungenGroupBox, "erfahrungenGroupBox");
            this.erfahrungenGroupBox.Name = "erfahrungenGroupBox";
            this.erfahrungenGroupBox.TabStop = false;
            // 
            // mehrAlsZehnJahreRadioButton
            // 
            resources.ApplyResources(this.mehrAlsZehnJahreRadioButton, "mehrAlsZehnJahreRadioButton");
            this.mehrAlsZehnJahreRadioButton.Name = "mehrAlsZehnJahreRadioButton";
            this.mehrAlsZehnJahreRadioButton.TabStop = true;
            this.mehrAlsZehnJahreRadioButton.UseVisualStyleBackColor = true;
            // 
            // fuenfBisNeunJahreRadioButton
            // 
            resources.ApplyResources(this.fuenfBisNeunJahreRadioButton, "fuenfBisNeunJahreRadioButton");
            this.fuenfBisNeunJahreRadioButton.Name = "fuenfBisNeunJahreRadioButton";
            this.fuenfBisNeunJahreRadioButton.TabStop = true;
            this.fuenfBisNeunJahreRadioButton.UseVisualStyleBackColor = true;
            // 
            // einBisVierJahreRadioButton
            // 
            resources.ApplyResources(this.einBisVierJahreRadioButton, "einBisVierJahreRadioButton");
            this.einBisVierJahreRadioButton.Name = "einBisVierJahreRadioButton";
            this.einBisVierJahreRadioButton.TabStop = true;
            this.einBisVierJahreRadioButton.UseVisualStyleBackColor = true;
            // 
            // unterEinJahrRadioButton
            // 
            resources.ApplyResources(this.unterEinJahrRadioButton, "unterEinJahrRadioButton");
            this.unterEinJahrRadioButton.Name = "unterEinJahrRadioButton";
            this.unterEinJahrRadioButton.TabStop = true;
            this.unterEinJahrRadioButton.UseVisualStyleBackColor = true;
            // 
            // programmiersprachenCheckedListBox
            // 
            this.programmiersprachenCheckedListBox.FormattingEnabled = true;
            resources.ApplyResources(this.programmiersprachenCheckedListBox, "programmiersprachenCheckedListBox");
            this.programmiersprachenCheckedListBox.Name = "programmiersprachenCheckedListBox";
            // 
            // zuruecksetzenButton
            // 
            resources.ApplyResources(this.zuruecksetzenButton, "zuruecksetzenButton");
            this.zuruecksetzenButton.Name = "zuruecksetzenButton";
            this.zuruecksetzenButton.UseVisualStyleBackColor = true;
            this.zuruecksetzenButton.Click += new System.EventHandler(this.zuruecksetzenButton_Click);
            // 
            // hinzufuegenButton
            // 
            resources.ApplyResources(this.hinzufuegenButton, "hinzufuegenButton");
            this.hinzufuegenButton.Name = "hinzufuegenButton";
            this.hinzufuegenButton.UseVisualStyleBackColor = true;
            this.hinzufuegenButton.Click += new System.EventHandler(this.hinzufuegenButton_Click);
            // 
            // schulstartDateTimePicker
            // 
            resources.ApplyResources(this.schulstartDateTimePicker, "schulstartDateTimePicker");
            this.schulstartDateTimePicker.Name = "schulstartDateTimePicker";
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
            // Form1
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.deleteSelectedParticipants);
            this.Controls.Add(this.allParticipantsListBox);
            this.Controls.Add(this.schoolPictureBox);
            this.Controls.Add(this.schulstartDateTimePicker);
            this.Controls.Add(this.hinzufuegenButton);
            this.Controls.Add(this.zuruecksetzenButton);
            this.Controls.Add(this.programmiersprachenCheckedListBox);
            this.Controls.Add(this.erfahrungenGroupBox);
            this.Controls.Add(this.schulstartLabel);
            this.Controls.Add(this.nachnameTextBox);
            this.Controls.Add(this.schulnameComboBox);
            this.Controls.Add(this.schuleLabel);
            this.Controls.Add(this.vornameTextBox);
            this.Controls.Add(this.nachnameLabel);
            this.Controls.Add(this.vornameLabel);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.ShowIcon = false;
            this.Load += new System.EventHandler(this.Form1_Load);
            this.erfahrungenGroupBox.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.schoolPictureBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label vornameLabel;
        private System.Windows.Forms.Label nachnameLabel;
        private System.Windows.Forms.TextBox vornameTextBox;
        private System.Windows.Forms.Label schuleLabel;
        private System.Windows.Forms.ComboBox schulnameComboBox;
        private System.Windows.Forms.TextBox nachnameTextBox;
        private System.Windows.Forms.Label schulstartLabel;
        private System.Windows.Forms.GroupBox erfahrungenGroupBox;
        private System.Windows.Forms.RadioButton unterEinJahrRadioButton;
        private System.Windows.Forms.RadioButton mehrAlsZehnJahreRadioButton;
        private System.Windows.Forms.RadioButton fuenfBisNeunJahreRadioButton;
        private System.Windows.Forms.RadioButton einBisVierJahreRadioButton;
        private System.Windows.Forms.CheckedListBox programmiersprachenCheckedListBox;
        private System.Windows.Forms.Button zuruecksetzenButton;
        private System.Windows.Forms.Button hinzufuegenButton;
        private System.Windows.Forms.DateTimePicker schulstartDateTimePicker;
        private System.Windows.Forms.PictureBox schoolPictureBox;
        private System.Windows.Forms.ListBox allParticipantsListBox;
        private System.Windows.Forms.Button deleteSelectedParticipants;
    }
}

