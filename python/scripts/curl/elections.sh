cd curl
source functions.sh
export SERVER_IP=127.0.0.1:5001

request GET "/elections" "Listado de eventos electorales del sistema"
