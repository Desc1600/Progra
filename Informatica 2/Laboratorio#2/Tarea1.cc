#import<iostream>
int main(){
    int empleados = 5; // se utilizo int ya que el numero de empleados es un numero entero
    float salario =110.50; // utilizo float ya que el salario es un numero real 
    empleados++;
    empleados++;
    empleados++;
    float sueldoTotal = empleados*salario; // se volvio a utilizar float ya que al multiplicar salario con empleado el resultado era un numero entero 
    float impuesto = 0.1; // utilizo float ya que el impuesto es un numero real
    float impuestoTotal = sueldoTotal * impuesto; // se volvio a utilizar float ya que al multiplicar sueldo total con impuesto el resultado era un numero entero  
    printf("El sueldo total de los empleados es : %f Y el impuesto total de los empleados es de: %f", sueldoTotal , impuestoTotal);
    
    return 0;

    // en conclusion con el const ya que nos fuimos por lo seguro con lo que respecta a los numeros enteros y numeros reales, en teroria se podria utilizar con el salario y el impuesto ya que estos datos no van a cambiar de valor
}
