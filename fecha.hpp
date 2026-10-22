#ifndef _FECHA_HPP
#define _FECHA_HPP

// Interfaz del TAD fecha. Pre-declaraciones:

/* Los valores del TAD fecha representan fechas válidas  
 * según las reglas del calendario gregoriano (adoptado en 1583) */
struct Fecha;

/* Dados los tres valores enteros dia, mes y anyo, se devuelve en f  
 * la fecha compuesta por ellos, y en error devuelve false. 
 * Parcial: se precisa que 1≤dia≤31, 1≤mes≤12, 1583≤anyo, y además 
 * que dia, mes y anyo formen una fecha válida según el calendario
 * gregoriano; de lo contrario, error devuelve el valor true */
void crear(int dia, int mes, int anyo, Fecha& f, bool& error);

/* Devuelve el dia de la fecha */
int dia(const Fecha& f);

/* Devuelve el mes de la fecha */
int mes(const Fecha& f);

/* Devuelve el año de la fecha */
int anyo(const Fecha& f);

/* Devuelve verdad si y sólo si f1 y f2 son la misma fecha */
bool iguales(const Fecha& f1, const Fecha& f2);

/* Devuelve verdad si y sólo si la fecha f1 es cronológicamente 
 * anterior a la fecha f2 */
bool anterior(const Fecha& f1, const Fecha& f2);

/* Devuelve verdad si y sólo si la fecha f1 es cronológicamente 
 * posterior a la fecha f2 */
bool posterior(const Fecha& f1, const Fecha& f2);

// Declaración

struct Fecha {
     friend void crear(int dia, int mes, int anyo, Fecha& f, bool& error) ;
     friend int dia(const Fecha& f);
     friend int mes(const Fecha& f);
     friend int anyo(const Fecha& f);
     friend bool iguales(const Fecha& f1, const Fecha& f2) ;
     friend bool anterior(const Fecha& f1, const Fecha& f2);
     friend bool posterior(const Fecha& f1, const Fecha& f2);

     private:
     // Representación de los valores del TAD.
       int elDia;
       int elMes;
       int elAnyo;
};

#endif
