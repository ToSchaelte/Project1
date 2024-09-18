namespace WindowsFormsApp20240828
{
    partial class DetailViewDialog
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
            this.detailsDataGridView = new System.Windows.Forms.DataGridView();
            this.Id = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.LastName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.FirstName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.School = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.SchoolEntry = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Experience = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ProgrammingLanguages = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.CountLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.detailsDataGridView)).BeginInit();
            this.SuspendLayout();
            // 
            // detailsDataGridView
            // 
            this.detailsDataGridView.AllowUserToAddRows = false;
            this.detailsDataGridView.AllowUserToDeleteRows = false;
            this.detailsDataGridView.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.detailsDataGridView.BackgroundColor = System.Drawing.SystemColors.ControlLightLight;
            this.detailsDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.detailsDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Id,
            this.LastName,
            this.FirstName,
            this.School,
            this.SchoolEntry,
            this.Experience,
            this.ProgrammingLanguages});
            this.detailsDataGridView.Location = new System.Drawing.Point(0, 23);
            this.detailsDataGridView.Margin = new System.Windows.Forms.Padding(4);
            this.detailsDataGridView.Name = "detailsDataGridView";
            this.detailsDataGridView.ReadOnly = true;
            this.detailsDataGridView.RowHeadersWidth = 51;
            this.detailsDataGridView.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.DisableResizing;
            this.detailsDataGridView.Size = new System.Drawing.Size(777, 667);
            this.detailsDataGridView.TabIndex = 0;
            // 
            // Id
            // 
            this.Id.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.DisplayedCells;
            this.Id.HeaderText = "ID";
            this.Id.MinimumWidth = 6;
            this.Id.Name = "Id";
            this.Id.ReadOnly = true;
            this.Id.Resizable = System.Windows.Forms.DataGridViewTriState.False;
            this.Id.Width = 49;
            // 
            // LastName
            // 
            this.LastName.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.DisplayedCells;
            this.LastName.HeaderText = "Last name";
            this.LastName.MinimumWidth = 6;
            this.LastName.Name = "LastName";
            this.LastName.ReadOnly = true;
            this.LastName.Width = 91;
            // 
            // FirstName
            // 
            this.FirstName.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.DisplayedCells;
            this.FirstName.HeaderText = "First Name";
            this.FirstName.MinimumWidth = 6;
            this.FirstName.Name = "FirstName";
            this.FirstName.ReadOnly = true;
            this.FirstName.Width = 93;
            // 
            // School
            // 
            this.School.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.DisplayedCells;
            this.School.HeaderText = "School";
            this.School.MinimumWidth = 6;
            this.School.Name = "School";
            this.School.ReadOnly = true;
            this.School.Width = 78;
            // 
            // SchoolEntry
            // 
            this.SchoolEntry.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.DisplayedCells;
            this.SchoolEntry.HeaderText = "At school since";
            this.SchoolEntry.MinimumWidth = 6;
            this.SchoolEntry.Name = "SchoolEntry";
            this.SchoolEntry.ReadOnly = true;
            this.SchoolEntry.Width = 116;
            // 
            // Experience
            // 
            this.Experience.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.DisplayedCells;
            this.Experience.HeaderText = "Experience";
            this.Experience.MinimumWidth = 6;
            this.Experience.Name = "Experience";
            this.Experience.ReadOnly = true;
            this.Experience.Width = 104;
            // 
            // ProgrammingLanguages
            // 
            this.ProgrammingLanguages.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.DisplayedCells;
            this.ProgrammingLanguages.HeaderText = "Programming Languages";
            this.ProgrammingLanguages.MinimumWidth = 6;
            this.ProgrammingLanguages.Name = "ProgrammingLanguages";
            this.ProgrammingLanguages.ReadOnly = true;
            this.ProgrammingLanguages.Width = 172;
            // 
            // CountLabel
            // 
            this.CountLabel.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.CountLabel.Location = new System.Drawing.Point(0, 0);
            this.CountLabel.Name = "CountLabel";
            this.CountLabel.Size = new System.Drawing.Size(756, 23);
            this.CountLabel.TabIndex = 1;
            this.CountLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // DetailViewDialog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.ClientSize = new System.Drawing.Size(777, 690);
            this.Controls.Add(this.CountLabel);
            this.Controls.Add(this.detailsDataGridView);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MinimizeBox = false;
            this.Name = "DetailViewDialog";
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.Text = "Details";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.DetailViewDialog_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.detailsDataGridView)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView detailsDataGridView;
        private System.Windows.Forms.DataGridViewTextBoxColumn Id;
        private System.Windows.Forms.DataGridViewTextBoxColumn LastName;
        private System.Windows.Forms.DataGridViewTextBoxColumn FirstName;
        private System.Windows.Forms.DataGridViewTextBoxColumn School;
        private System.Windows.Forms.DataGridViewTextBoxColumn SchoolEntry;
        private System.Windows.Forms.DataGridViewTextBoxColumn Experience;
        private System.Windows.Forms.DataGridViewTextBoxColumn ProgrammingLanguages;
        private System.Windows.Forms.Label CountLabel;
    }
}