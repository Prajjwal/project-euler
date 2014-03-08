File.open "../input/p13.txt", "r" do |f|
  puts f.readlines.map { |n| n.to_i }.reduce(:+).to_s[0, 10]
end
