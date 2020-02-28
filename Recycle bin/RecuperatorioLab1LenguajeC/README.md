# RecuperatorioLab1LenguajeC
- Recuperatorio primer parcial de Laboratorio 1
- Andrés Caballero Streppel
- División: 1-B

**Notas:**
- Al egresar vehículo el estado pasa a -2, esto para ahorrar en una estructura nueva, 
facilitar el re-ingreso del mismo auto en un futuro update, también como para listar autos egresados.
- Las horas que estará el vehículo se cargan al ingresar los datos individualmente en la estructura, 
así cada vez que se pide la recaudación total no tire un número diferente. Esto se podría solucionar de una
forma diferente, pero decidí hacerlo de esta manera para aprovechar la funcion _devolverHorasEstadia_.

**Problemas:**
- Faltan validaciones de inputs
- No se puede cargar las implementaciones de las funciones que utilizan dos estructuras diferentes.
- Hay un bug que al pedir ID, devuelve el mismo entero, pero restado. Y con este problema no me deja interactuar con los datos de los indices número 1
pero sí con el resto.