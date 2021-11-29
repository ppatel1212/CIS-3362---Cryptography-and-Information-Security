from num1 import quickMod


def main():

    #Obtain the values of the given values
    p = int(input("Enter a large prime number for public key 'p': "))
    g = int(input("Enter a generator value for 'g': "))
    a = int(input("Enter Alice's secret key 'a: "))
    b = int(input("Enter Bob's secret key 'b': "))

    #Pass the given values to the quickMod function from question one's Python program. These values below will
    #show what Alice sends Bob and vice-versa
    print("Alice sends Bob C1 which is "+str(quickMod(g, a, p)))
    print("Bob sends Alice C2 which is "+str(quickMod(g, b, p)))

    #Because the shared key will result in the same value, we can put it in once
    print("The shared key is: "+str(quickMod(g, a*b, p)))


if __name__ == "__main__":
    main()