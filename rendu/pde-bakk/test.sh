
count=1
:> time.log
mkdir -p ../../ressources/output
while [ $count -lt 11 ]; do
  input_fname="../../ressources/generated-${count}"
  output_fname="../../ressources/output/generated-${count}"
  echo "input_fname is $input_fname , output is $output_fname"
  (time ./hotrace > $output_fname) 2>time.log <$input_fname
  ((count++))
done
