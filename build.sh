#Mac sheet to build programs, same as make file

g++ sha256.cpp miner.cpp -o miner
g++ terminal.cpp wallet.cpp -o wallet
chmod 755 background.sh
