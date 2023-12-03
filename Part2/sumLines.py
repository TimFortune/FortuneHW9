# Tim Fortune HW9 Part 2
# sumLines.py
# Description:
#    A Python script that reads a text file, computes the sum, number of integers, and the average of all numbers.
#    The code follows the example 'tme.py' studied in class. It computes the sum, number of elements,
#    and average through simple list manipulation, addition, and division.
#
# Command Line Arguments:
#    <input_file>: Path to the input text file containing numbers.
#
# Example Invocation from assignment page:
#    $ python3 sumLines.py dataInput.txt
#    Where sum = 917, Number of Elments = 26, and Average = 35.26923076923077
#
import sys

def sum_lines(file_path):
    try:
        with open(file_path, 'r') as file:

            # Initialize variables for sum and count
            total_sum = 0
            total_count = 0

            # Iterate though each line in the file
            for line in file:

                # Split the line into a list of integers
                numbers = list(map(int, line.split()))

                # Update the total sum and count
                total_sum += sum(numbers)
                total_count += len(numbers)

            
            average = total_sum / total_count if total_count > 0 else 0		# Calculate the average

           
            print(f"{total_sum} {total_count} {average}")	 # Print the result

    except FileNotFoundError:
        print(f"Error: File not found - {file_path}")
    except Exception as e:
        print(f"Error: {e}")

# Check if the script is invoked with the correct number of command line arguments
if len(sys.argv) != 2:
    print("Usage: python3 sumLines.py <input_file>")
    sys.exit(1)


input_file = sys.argv[1]	# Get the file path from the command line arguments


sum_lines(input_file) 	# Call the main function with the provided file path
