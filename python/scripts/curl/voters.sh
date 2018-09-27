cd curl
source functions.sh
export SERVER_IP=127.0.0.1:5001

request GET "/voters" "Listado de todos los votantes registrados en el sistema"
request GET "/voters/1" "Detalles del votante de id 1"

