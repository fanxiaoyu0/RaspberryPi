

def main():
    alpha=0
    beta=0
    with open('./data.log', 'r') as f:
        lines = f.readlines()[1:]
        for line in lines:
            line = line.split(',')
            if line[1]==line[2]:
                alpha+=1
            if line[3]==line[4]:
                beta+=1
        print('alpha:', alpha/len(lines))
        print('beta:', beta/len(lines))

if __name__ == '__main__':
    main()
    print("All is well!")