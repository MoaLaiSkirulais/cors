cd curl
source functions.sh
export SERVER_IP=127.0.0.1:5001

request POST "/votes" "Usuario de facebook vota en el evento local #1.
Elige la lista #1. Envía sus credenciales y el tipo de autenticación seleccionada. 
El evento local se corresponde con la localización del usuario." "votes-facebook.json"
