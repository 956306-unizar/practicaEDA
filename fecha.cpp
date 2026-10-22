#include "fecha.hpp"
   
// Implementacion de las operaciones del TAD fecha.

   // Operaciones auxiliares sobre enteros.

   // Devuelve verdad si y sólo si el año a es bisiesto.
   bool esBisiesto(int a) {
     return (a % 4 == 0 && !(a % 100 == 0 && a % 400 != 0));
   }

   // Devuelve verdad si y sólo si (d,m,a) representan una fecha válida.
   bool esFechaValida(int d, int m, int a) {
     bool valida = 1583 <= a && 1 <= m && m <= 12;
     if (valida) {
       switch (m) {
         case 4: case 6: case 9: case 11: 
           valida = 1 <= d && d <= 30; 
           break;
         case 1: case 3: case 5: case 7: case 8: case 10: case 12:
           valida = 1 <= d && d <= 31;
           break;
         case 2: 
           if (!esBisiesto(a)) {
             valida = 1 <= d && d <= 28;
           }
           else
             valida = 1 <= d && d <= 29;
           break;
       }         
     }
     return valida;
   }

   void crear(int dia, int mes, int anyo, Fecha& f, bool& error) {
     if (esFechaValida(dia, mes, anyo)) {
       f.elDia = dia;
       f.elMes = mes;
       f.elAnyo = anyo;
       error = false;
     }
     else
       error = true;
   };
   
   int dia(const Fecha& f) {
       return f.elDia;
   };

   int mes(const Fecha& f) {
       return f.elMes;
   };

   int anyo(const Fecha& f) {
       return f.elAnyo;
   };

   bool iguales(const Fecha& f1, const Fecha& f2) {
       return f1.elDia == f2.elDia && f1.elMes == f2.elMes && f1.elAnyo == f2.elAnyo;
   };

   bool anterior(const Fecha& f1, const Fecha& f2) {
       return f1.elAnyo <  f2.elAnyo || 
              (f1.elAnyo == f2.elAnyo && f1.elMes < f2.elMes) ||
              (f1.elAnyo == f2.elAnyo && f1.elMes == f2.elMes && f1.elDia < f2.elDia);
   };

   bool posterior(const Fecha& f1, const Fecha& f2) {
       return !iguales(f1,f2) && !anterior(f1,f2);
   };
    


