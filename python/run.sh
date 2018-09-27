# virtualenv .cors
# source .cors/bin/activate
# pip install -r requirements.txt
# python -V
# pip freeze --local > requirements.txt

# export testName="$1"
# python $testName

source .cors/bin/activate

export testName="tests/main.py"
python $testName

# jupyter notebook --allow-root --ip=0.0.0.0