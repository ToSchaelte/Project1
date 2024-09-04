using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;

namespace WindowsFormsApp20240828
{
    public static class StaticProperties
    {
        public static Color DefaultBackColor { get; set; }

        public static Color DefaultForeColor { get; set; }

        public static Font DefaultFont { get; set; }

        public static Configuration Config { get; set; } = new Configuration();

        public static Dictionary<string, Image> Schools { get; } = new Dictionary<string, Image>
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

        public static List<string> ProgrammingLanguages { get; } = new List<string>
        {
                "Cobol",
                "Basic",
                "C",
                "C++",
                "Delphi",
                "Java",
                "C#"
        };

        public static List<Participant> Participants { get; } = new List<Participant>();

        public static string ParticipantsFilename => "Participants.xml";

        public static string ConfigFilename => "Configuration.xml";

        public static string AppdataDirectory => Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), "Fumo_69_420");

        public static string ParticipantsPath => Path.Combine(AppdataDirectory, ParticipantsFilename);

        public static string ConfigPath => Path.Combine(AppdataDirectory, ConfigFilename);
    }
}
