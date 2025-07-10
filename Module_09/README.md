# Module_09

## Usage

```zsh
# Generate numbers in command line
./PmergeMe $(for i in {1..10}; do echo $((RANDOM % 1000 + 1)); done)
```

```zsh
## Use included generator program
make generator && ./PmergeMe $(./generator 10 100)
```

## TODO

**M8**

- `<typename Container>` for M08?
- MutatedStack complete copy/assignemnt constructors.

- Makefile must contain `re` rule.