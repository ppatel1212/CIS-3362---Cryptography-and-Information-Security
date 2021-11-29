#Prince Patel
#Quick expo

from math import gcd

#This function speeds up the process of large exponentiations
def quickMod(num, exponent, mod):

    #Like any recursive funtion, we need a case to break out of the recursion
    #In this case we break out when the exponent is at 0
    if exponent == 0:
        return 1
    
    #Referenced part of the function from notes done in class when I got suck on how divide
    # divide properly. Here we check to see if the exponent is even, if it is then we will
    # divide by 2 that way we only have to do half as much of the work.
    if exponent % 2 == 0:
        recurValReturned = quickMod(num, exponent//2, mod)
        return (recurValReturned*recurValReturned) % mod
    
    #In this return value, we will recursively call the function but in this function
    #we will subtract 1 from an odd value to make it even so we can divide by two recursively
    #from the return value above
    return (num*quickMod(num, exponent-1, mod)) % mod


def main():

    #Declare variable for placeholder when saving the modded values
    j = 0
    #Declare variable for the a1...a12
    exponent = []
    #Declare vairable to store the values returned with caluclating quickMod
    quickModVals = []

    modVal = int(input("Enter the mod value: "))
    genVal = int(input("Enter the generator value: "))

    for i in range(1, modVal-1): #Use '-1' because modVal is divisible by itself
        
        #We must find the GCD so we know if 'a1' is relatively prime to modVal
        if (gcd(i, modVal-1)) == 1:
            #Add to exponent list so we have list of relatively prime values
            exponent.append(i)

    #Use a loop to find the values at the requested a10...a12. Range must be: (desired location - 1) because of list.
    for i in range(9, 12):
        print("a"+str(i+1)+": "+ str(exponent[i]))

    #Create another loop to pass in values to mod numbers fast (quickMod()).
    for i in range(9, 12):
        returnedVal = quickMod(genVal, exponent[i], modVal)
        
        #Saved the value that is returned to the quickModVals
        quickModVals.append(returnedVal)

        j += 1
    
    print("The remainders are the following: ")
    
    for i in quickModVals:
        print(i)

if __name__ == "__main__":
    main()
