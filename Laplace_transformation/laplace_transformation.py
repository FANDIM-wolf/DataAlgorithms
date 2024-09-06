import numpy as np
import sympy as sp
import matplotlib.pyplot as plt

def laplace_transform(coefficients):
    """
    Laplace transform for a linear differential equation

    Parameters:
    coefficients (list): coefficients of the differential equation

    Returns:
    s (symbol): symbol for s
    transfer_function (str): transfer function
    """
    # Get the coefficients of the differential equation
    a_coeffs = coefficients[0]
    b_coeffs = coefficients[1]

    # Define the variable s
    s = sp.symbols('s')

    # Define the transfer function
    
    Y_s = sum([a*s**i for i, a in enumerate(reversed(a_coeffs))])
    X_s = sum([b*s**i for i, b in enumerate(reversed(b_coeffs))])

    # Find the transfer function
    transfer_function = X_s / Y_s

    return s, sp.simplify(transfer_function)

# Example usage
coefficients = [[6, 40, 256], [128]]  # coefficients of the differential equation
s, transfer_function = laplace_transform(coefficients)
print(transfer_function)

# Create a numerical function from the transfer function
transfer_function_num = sp.lambdify(s, transfer_function)

# Create an array of numerical values for s
s_values = np.linspace(0, 10, 1000)

# Evaluate the transfer function numerically for each s value
transfer_function_values = [transfer_function_num(s_value) for s_value in s_values]

# Plot the transfer function
plt.plot(s_values, transfer_function_values)
plt.xlabel('s')
plt.ylabel('Transfer Function')
plt.title('Plot of the Transfer Function')
plt.show()