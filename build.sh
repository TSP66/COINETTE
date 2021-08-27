#Mac sheet to build programs, same as make file

g++ sha256.cpp miner.cpp -o miner
g++ terminal.cpp wallet.cpp -o wallet
g++ connections.cpp -o node
chmod 755 background.sh
