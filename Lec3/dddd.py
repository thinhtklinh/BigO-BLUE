# Initial hex string
hex_string = "b6bfa4b9bff1beb4"

# Step 1: Convert hex string to bytes
bytes_data = bytes.fromhex(hex_string)

# Step 2: XOR each byte with 0xD1
xor_bytes = [b ^ 0xD1 for b in bytes_data]

# Step 3: Reverse the byte sequence
reversed_bytes = xor_bytes[::-1]

# Step 4: Convert to ASCII string
ascii_string = ''.join(chr(b) for b in reversed_bytes)

# Print the result
print(ascii_string)