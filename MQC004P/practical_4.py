from qiskit import QuantumCircuit
from qiskit.quantum_info import Statevector

def generate_bell_state(state_type):
    qc = QuantumCircuit(2)
    qc.h(0)
    qc.cx(0, 1)
    if state_type == "Phi-":
        qc.z(0)
    elif state_type == "Psi+":
        qc.x(1)
    elif state_type == "Psi-":
        qc.x(1)
        qc.z(0)

    state = Statevector.from_instruction(qc)
    print("Bell State:", state_type)
    print(qc.draw())
    print(state)
    print("-" * 40)
# Function calls
generate_bell_state("Phi+")
generate_bell_state("Phi-")
generate_bell_state("Psi+")
generate_bell_state("Psi-")
