using System.Drawing;
using System.Xml.Serialization;

namespace WindowsFormsApp20240828
{
    public class Configuration
    {
        private static readonly FontConverter _fontConverter = new FontConverter();

        [XmlIgnore]
        public Color BackColor { get; set; }

        [XmlAttribute(nameof(BackColor))]
        public string BackColorString
        {
            get =>  ColorTranslator.ToHtml(BackColor);
            set => BackColor = ColorTranslator.FromHtml(value);
        }

        [XmlIgnore]
        public Color ForeColor { get; set; }

        [XmlAttribute(nameof(ForeColor))]
        public string ForeColorString
        {
            get => ColorTranslator.ToHtml(ForeColor);
            set => ForeColor = ColorTranslator.FromHtml(value);
        }

        [XmlIgnore]
        public Font Font { get; set; }

        [XmlAttribute(nameof(Font))]
        public string FontString
        {
            get => _fontConverter.ConvertToString(Font);
            set => Font = (Font)_fontConverter.ConvertFromString(value);
        }
    }
}
