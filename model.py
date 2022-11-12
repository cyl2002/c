from tensorflow.keras.models import Model
from tensorflow.keras.layers import *


class Mymodel(Model):
    def __init__(self,x1,x2,x3,x4, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.b11 = Conv2D(x1,kernel_size=(1,1),activation="relu",padding="same")
        
        self.b21 = Conv2D(x2[0],kernel_size=(1,1),activation="relu",padding="same")
        self.b22 = Conv2D(x2[1],kernel_size=(3,3),activation="relu",padding="same")
        
        self.b31 = Conv2D(x3[0],kernel_size=(1,1),activation="relu",padding="same")
        self.b32 = Conv2D(x3[1],kernel_size=(5,5),activation="relu",padding="same")
        
        self.b41= MaxPooling2D(pool_size=(3,3),strides=(1,1),padding='same')
        self.b42 = Conv2D(x4,(1,1),padding='same',strides=(1,1),name=None)
        self.f =Flatten()
    def call(self, inputs):
        
        p1  = self.b11(inputs)
        p2  = self.b22(self.b21(inputs))
        p3  = self.b32(self.b31(inputs))
        p4 =  self.b42(self.b41(inputs))
        p5 =  concatenate([p1,p2,p3,p4],axis=3)
        p6 = self.f(p5)
        return p6
    
if __name__ == "__main__":
    model = Mymodel(12,[12,12],[24,24],12)
    model(Input(shape=(224,224,3)))
    
    model.summary()