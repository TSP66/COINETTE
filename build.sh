#Mac sheet to build programs, same as make file

g++ sha256.cpp miner.cpp -o miner
g++ wallet.cpp terminal.cpp -o wallet
chmod 755 background.sh
