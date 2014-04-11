void HeartRate () 
{
  if (ledMetro.check() == 1) { // verificar se o metro ultrapassou o seu intervalo
    if (estado==HIGH) {
      estado=LOW;
      ledMetro.reset(); // Se o estado do LED é HIGH, o intervalo é definido com 0.25 segundos.
    }
    else {
      ledMetro.reset(); // /Se o estado do LED é LOW, o intervalo é definido com 1 segundo.
      estado=HIGH;
    }
    digitalWrite(LED,estado);
  }
}



