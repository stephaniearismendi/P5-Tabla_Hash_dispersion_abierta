# Tabla Hash de dispersión Abierta.

Se pide desarrollar un tipo de dato genérico _TablaHash<class Clave>_ para almacenar valores de tipo **Clave** utilizando la técnica de búsqueda por dispersión abierta.

Esta técnica se basa en la existencia de funciones de dispersión, que reciben como parámetro un valor de tipo Clave y retorna la posición de la tabla, en el rango 
[0..nDatos-1], donde corresponde almacenar dicho valor de clave. En la práctica se pide implementar, al menos, las funciones de dispersión módulo y pseudoaleatoria.
