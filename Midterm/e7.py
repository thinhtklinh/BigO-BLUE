from queue import Queue

def bfs_shortest_path(start, end, dictionary):
    if start == end:
        return 0
    
    q = Queue()
    q.put((start, 0)) # Initialize list as queue with the starting word and depth 0
    visited = set(start)  # Set to keep track of visited words
    
    while not q.empty():
        current_word, current_depth = q.get()  # Pop from the front (less efficient)
        
        # Generate all possible one-letter transformations
        for i in range(len(current_word)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                if c != current_word[i]:
                    next_word = current_word[:i] + c + current_word[i+1:]
                    if next_word == end:
                        return current_depth + 1
                    if next_word in dictionary and next_word not in visited:
                        visited.add(next_word)
                        q.put((next_word, current_depth + 1))  # Append to the end
    
    return -1  # If no transformation sequence is found

def word_transformation():
    number_of_cases = int(input().strip())
    results = []
    
    for _ in range(number_of_cases):
        input()  # Read the blank line
        
        dictionary = set()
        while True:
            word = input().strip()
            if word == '*':
                break
            dictionary.add(word)
        
        while True:
            try:
                line = input().strip()
                if line == "":
                    break
            except:
                break
            start_word, end_word = line.split()
            steps = bfs_shortest_path(start_word, end_word, dictionary)
            results.append(f"{start_word} {end_word} {steps}")
        
        results.append("")  # Blank line between cases
    
    print("\n".join(results))

# Run the function
word_transformation()