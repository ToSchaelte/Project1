using System;
using System.Collections.Generic;

namespace WindowsFormsApp20240828.Helpers
{
    public static class PropertyHelper
    {
        public static void SetAndNotify<T>(ref T field, T value, string propertyName,
            Action<string> propertyChangedCallback = null)
        {
            if (EqualityComparer<T>.Default.Equals(field, value)) return;
            field = value;
            propertyChangedCallback?.Invoke(propertyName);
        }
    }
}
