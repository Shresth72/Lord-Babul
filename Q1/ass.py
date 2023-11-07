# Define the instruction set architecture
instructions = {
    'MOV': 0x00,
    'ADD': 0x01,
    'SUB': 0x02,
    'JMP': 0x03,
}

# Define the registers
registers = {
    'R0': 0x00,
    'R1': 0x01,
    'R2': 0x02,
    'R3': 0x03,
}

def assemble(instruction, operand1, operand2):
    if instruction not in instructions:
        raise ValueError(f"Invalid instruction: {instruction}")

    if operand1 not in registers:
        raise ValueError(f"Invalid operand: {operand1}")

    if operand2 not in registers:
        raise ValueError(f"Invalid operand: {operand2}")

    opcode = instructions[instruction]
    reg1 = registers[operand1]
    reg2 = registers[operand2]

    # Combine the opcode and register values to form the machine code
    machine_code = (opcode << 6) | (reg1 << 3) | reg2

    return machine_code

# Example usage:
instruction = 'MOV'
operand1 = 'R0'
operand2 = 'R1'
machine_code = assemble(instruction, operand1, operand2)
print(f"Machine code for {instruction} {operand1}, {operand2}: {machine_code:02X}")
