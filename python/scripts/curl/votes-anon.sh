cd curl
source functions.sh
export SERVER_IP=127.0.0.1:5001

request POST "/votes" "Usuario anónimo vota en eleccionlocal #1.
Elige la lista #1. Solo se lo identifica por su dirección IP." "votes-anon.json"

