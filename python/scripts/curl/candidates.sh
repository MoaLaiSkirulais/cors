cd curl
source functions.sh
export SERVER_IP=127.0.0.1:5001

request GET "/elections/1/localelections/1/lists/1/candidates" "Lista de candidatos correspondientes a la lista local #1"
