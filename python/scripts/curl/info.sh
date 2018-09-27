source functions.sh
export SERVER_IP=127.0.0.1:5001

# list
log "Backups by Printers" "sl" "monitor"	
curl -X GET -H "Content-Type: application/json" $SERVER_IP/info  | jq .