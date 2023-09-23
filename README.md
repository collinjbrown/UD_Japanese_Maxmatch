# UD_Japanese_Maxmatch
 An implementation of the maxmatch algorithm using the Japanese treebank from the Universal Dependencies project.

 Given the UD Japanese dataset it achieves a Word Error Rate of 6.74%.

# How to Run
 This assumes you're building the CMake project yourself, though I'll include a build in the repo just
 to make sure we don't run into any issues.
 
 1. Add a directory, "datasets", with two subdirectories: "input" and "output".
 2. Move your training and testing data to the "datasets/input" directory and rename your
 training data to "train.conllu" and your testing data to "test.conllu".
 3. If you have VS Studio, you can open this directory with it which should automatically build
 the CMake project. Otherwise, you will have to build it however you see fit.
 4. Run the executable or initiate the build in VS Studio.
 5. Wait. This really shouldn't take too long.
 6. Go into the build's "datasets/output" directory. This should have the "reference.txt" and "hypothesis.txt"
 files. If not, try using the build I've included in the repo.
 
 If this isn't successful and you can reach out to me, I'd be happy to fix any issues. I'll be sure to
 test this on other machines since I'm running on Windows right now.
