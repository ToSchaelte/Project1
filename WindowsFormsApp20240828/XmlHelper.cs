using System.Xml.Serialization;
using System.Xml;
using System.Text;
using System.IO;
using System;

namespace WindowsFormsApp20240828
{
    public class XmlHelper
    {
        #region Serializer

        public static object DeserializeXml<T>(string filepath, Type[] extraTypes = null)
        {
            try
            {
                using (var fileStream = new FileStream(filepath, FileMode.Open, FileAccess.Read))
                {
                    var result = new XmlSerializer(typeof(T), extraTypes).Deserialize(fileStream);
                    if (result != null) return result;
                }
                return null;
            }
            catch
            {
                return null;
            }
        }

        public static bool SerializeXml<T>(T item, string filepath, Type[] extraTypes = null)
        {
            var directory = Path.GetDirectoryName(filepath);
            if (!string.IsNullOrEmpty(directory) && !Directory.Exists(directory)) Directory.CreateDirectory(directory);
            try
            {
                using (var fileStream = new FileStream(filepath, FileMode.Create))
                {
                    SerializeXml(item, fileStream, extraTypes);
                }
                return true;
            }
            catch (IOException)
            {
                return false;
            }
        }

        public static bool SerializeXml<T>(T item, FileStream fileStream, Type[] extraTypes = null)
        {
            try
            {
                new XmlSerializer(typeof(T), extraTypes).Serialize(XmlWriter.Create(fileStream, new XmlWriterSettings { Indent = true }), item);
                return true;
            }
            catch (IOException)
            {
                return false;
            }
        }

        #endregion
    }
}
