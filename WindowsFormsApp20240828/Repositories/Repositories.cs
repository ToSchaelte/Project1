using System.Data;

namespace WindowsFormsApp20240828.Repositories
{
    public class Repositories
    {
        public ParticipantRepository ParticipantRepository { get; private set; }

        public Repositories(IDbConnection dbConnection)
        {
            ParticipantRepository = new ParticipantRepository(dbConnection);
        }
    }
}
