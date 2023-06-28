import abc
from collections import namedtuple

ModelWeightsDescriptor = \
    namedtuple('ModelWeightsDescriptor',
               ['weights_names', 'weights_trainable', 'weights_values'])

class MetisModel(object):
    @abc.abstractmethod
    def load(self, model_dir):
        pass
    
    @abc.abstractmethod
    def save(self, model_dir) -> None:
        pass
    
    def get_weights_descriptor(self) -> ModelWeightsDescriptor:
        pass
        
    @abc.abstractmethod
    def set_model_weights(self, model_weights_descriptor: ModelWeightsDescriptor):
        pass
    
    @abc.abstractmethod
    def get_neural_engine(self):
        pass