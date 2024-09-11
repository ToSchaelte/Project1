
using System;
using System.Data;
using System.Data.OleDb;
using System.Data.SQLite;
using System.IO;

namespace WindowsFormsApp20240828
{
    public class DbHandler
    {
        public IDbConnection DbConnection { get; private set; }

        public DbHandler()
        {
        }

        public bool OpenOleDbConnection()
        {
            try
            {
                DbConnection = new OleDbConnection($"Provider=Microsoft.ACE.OLEDB.12.0;" +
                    $"Data Source={Path.Combine(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Data"), "TeilnehmerITB26.accdb")}");
                DbConnection.Open();
                Repositories = new Repositories.Repositories(DbConnection);
                return true;
            }
            catch
            {
                return false;
            }
        }

        public bool OpenSQLiteConnection()
        {
            try
            {
                DbConnection = new SQLiteConnection($"Provider=System.Data.SQLite;" +
                    $"Data Source={Path.Combine(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Data"), "TeilnehmerITB26.s3db")}");
                DbConnection.Open();
                Repositories = new Repositories.Repositories(DbConnection);
                return true;
            }
            catch
            {
                return false;
            }
        }

        public Repositories.Repositories Repositories { get; private set; }
    }
}
