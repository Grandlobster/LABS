from qiskit import QuantumCircuit
from qiskit.quantum_info import Statevector

# Paul X-axis
qc_x= QuantumCircuit(1)
qc_x.x(0)
print(qc_x.draw())
print("Pauli X ", Statevector.from_instruction(qc_x))

#Pauli Y-xis 
qc_y=QuantumCircuit(1)
qc_y.y(0)
print(qc_y.draw())
print("Pauli Y", Statevector.from_instruction(qc_y))

# Pauli Z Gate
qc_1=QuantumCircuit(1)
qc_1.x(0)
qc_1.y(0)
State_1=Statevector(qc_1)
print(State_1)
print(qc_1.draw())
print(" Pauli Z", Statevector.from_instruction(qc_1))

'''# Hadamard Gate 
qc_x.h(0)
print(qc_x.draw())'''
