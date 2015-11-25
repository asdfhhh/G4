from math import exp

from math import tanh

class test:
	def value(self,index,in0,in1,in2):
		self.input0 = (in0 - 0)/1
		self.input1 = (in1 - 0)/1
		self.input2 = (in2 - 0)/1
		if index==0: return self.neuron0x8da2e68();
		return 0.
	def neuron0x8b158f8(self):
		return self.input0
	def neuron0x8defea0(self):
		return self.input1
	def neuron0x8da2c68(self):
		return self.input2
	def neuron0x8da2f90(self):
		input = 0.255818
		input = input + self.synapse0x8da3148()
		input = input + self.synapse0x8da3170()
		input = input + self.synapse0x8da3198()
		if input<-709. : return 0
		return ((1/(1+exp(-input)))*1)+0
	def neuron0x8da31c0(self):
		input = 0.478818
		input = input + self.synapse0x8da33c0()
		input = input + self.synapse0x8da33e8()
		input = input + self.synapse0x8da3410()
		if input<-709. : return 0
		return ((1/(1+exp(-input)))*1)+0
	def neuron0x8da3438(self):
		input = -0.313639
		input = input + self.synapse0x8da3638()
		input = input + self.synapse0x8da3660()
		input = input + self.synapse0x8da3688()
		if input<-709. : return 0
		return ((1/(1+exp(-input)))*1)+0
	def neuron0x8a85928(self):
		input = 0.161331
		input = input + self.synapse0x8a85b28()
		input = input + self.synapse0x8a85b50()
		input = input + self.synapse0x8a85b78()
		if input<-709. : return 0
		return ((1/(1+exp(-input)))*1)+0
	def neuron0x8a85ba0(self):
		input = -0.0868824
		input = input + self.synapse0x8a85da0()
		input = input + self.synapse0x8a85dc8()
		input = input + self.synapse0x8a85df0()
		if input<-709. : return 0
		return ((1/(1+exp(-input)))*1)+0
	def neuron0x8a85e18(self):
		input = -0.286119
		input = input + self.synapse0x8a86030()
		input = input + self.synapse0x8a86058()
		input = input + self.synapse0x860a528()
		input = input + self.synapse0x8c018b8()
		input = input + self.synapse0x8adc850()
		if input<-709. : return 0
		return ((1/(1+exp(-input)))*1)+0
	def neuron0x8a86108(self):
		input = -0.473392
		input = input + self.synapse0x8a862d8()
		input = input + self.synapse0x8a86300()
		input = input + self.synapse0x8a86328()
		input = input + self.synapse0x8a86350()
		input = input + self.synapse0x8a86378()
		if input<-709. : return 0
		return ((1/(1+exp(-input)))*1)+0
	def neuron0x89a6208(self):
		input = -0.606907
		input = input + self.synapse0x89a6420()
		input = input + self.synapse0x89a6448()
		input = input + self.synapse0x89a6470()
		input = input + self.synapse0x89a6498()
		input = input + self.synapse0x89a64c0()
		if input<-709. : return 0
		return ((1/(1+exp(-input)))*1)+0
	def neuron0x8da2e68(self):
		input = 1.48155
		input = input + self.synapse0x8da36f8()
		input = input + self.synapse0x8df00e8()
		input = input + self.synapse0x8df0110()
		return (input*1)+0
	def synapse0x8da3148(self):
		return (self.neuron0x8b158f8()*-0.291849)
	def synapse0x8da3170(self):
		return (self.neuron0x8defea0()*-0.0725572)
	def synapse0x8da3198(self):
		return (self.neuron0x8da2c68()*0.400455)
	def synapse0x8da33c0(self):
		return (self.neuron0x8b158f8()*-0.238176)
	def synapse0x8da33e8(self):
		return (self.neuron0x8defea0()*0.290424)
	def synapse0x8da3410(self):
		return (self.neuron0x8da2c68()*-0.0977482)
	def synapse0x8da3638(self):
		return (self.neuron0x8b158f8()*-0.233899)
	def synapse0x8da3660(self):
		return (self.neuron0x8defea0()*-0.47159)
	def synapse0x8da3688(self):
		return (self.neuron0x8da2c68()*0.175991)
	def synapse0x8a85b28(self):
		return (self.neuron0x8b158f8()*-0.353854)
	def synapse0x8a85b50(self):
		return (self.neuron0x8defea0()*-0.236215)
	def synapse0x8a85b78(self):
		return (self.neuron0x8da2c68()*-0.0733264)
	def synapse0x8a85da0(self):
		return (self.neuron0x8b158f8()*0.192492)
	def synapse0x8a85dc8(self):
		return (self.neuron0x8defea0()*-0.113805)
	def synapse0x8a85df0(self):
		return (self.neuron0x8da2c68()*-0.290885)
	def synapse0x8a86030(self):
		return (self.neuron0x8da2f90()*-0.329451)
	def synapse0x8a86058(self):
		return (self.neuron0x8da31c0()*-0.0544566)
	def synapse0x860a528(self):
		return (self.neuron0x8da3438()*-0.0745863)
	def synapse0x8c018b8(self):
		return (self.neuron0x8a85928()*-0.0136516)
	def synapse0x8adc850(self):
		return (self.neuron0x8a85ba0()*-0.498025)
	def synapse0x8a862d8(self):
		return (self.neuron0x8da2f90()*0.00911774)
	def synapse0x8a86300(self):
		return (self.neuron0x8da31c0()*0.0797611)
	def synapse0x8a86328(self):
		return (self.neuron0x8da3438()*-0.398704)
	def synapse0x8a86350(self):
		return (self.neuron0x8a85928()*0.03239)
	def synapse0x8a86378(self):
		return (self.neuron0x8a85ba0()*0.00596061)
	def synapse0x89a6420(self):
		return (self.neuron0x8da2f90()*0.14165)
	def synapse0x89a6448(self):
		return (self.neuron0x8da31c0()*0.169203)
	def synapse0x89a6470(self):
		return (self.neuron0x8da3438()*-0.00234873)
	def synapse0x89a6498(self):
		return (self.neuron0x8a85928()*-0.373076)
	def synapse0x89a64c0(self):
		return (self.neuron0x8a85ba0()*-0.312573)
	def synapse0x8da36f8(self):
		return (self.neuron0x8a85e18()*0.445943)
	def synapse0x8df00e8(self):
		return (self.neuron0x8a86108()*0.705444)
	def synapse0x8df0110(self):
		return (self.neuron0x89a6208()*0.39051)
