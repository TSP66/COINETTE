from fastecdsa import keys, curve,ecdsa
import os

class key:
    
    def __init__(self, priv_key=None, pub_key=None, load=None):
        
        if(load == True):
            with open("public_key.txt", "w+") as file:
                self.pub_key = file.read()
            
            with open("private_key.txt", "w+") as file:
                self.priv_key = file.read()
        
        else:
            
            if(priv_key==None):
                self.priv_key, self.pub_key = keys.gen_keypair(curve.P256)
            else:
                self.priv_key, self.pub_key = priv_key,pub_key

    def encrypt(self, message):
        (r,s) = ecdsa.sign(message,self.priv_key)
        return((r,s))

    def verify(self, z, message, pub_key):
        valid = ecdsa.verify(z,message,pub_key)

    def save(self):
    
        with open("public_key.txt", "w+") as file:
            file.write(self.pub_key)

        with open("private_key.txt", "w+") as file:
            file.write(self.priv_key)
            
    def dump(self):
        print(self.priv_key)
        print(self.pub_key)



