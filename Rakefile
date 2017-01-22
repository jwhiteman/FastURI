require "bundler/gem_tasks"

require "rake/testtask"

Rake::TestTask.new(:test) do |t|
  t.libs << "test"
  t.libs << "lib"
  t.test_files = FileList['test/**/*_test.rb']
end

require "rake/extensiontask"

task build: :compile

Rake::ExtensionTask.new("fast_uri") do |ext|
  ext.lib_dir = "lib/fast_uri"
end

task default: %i(clobber ragel compile test)

task :ragel do
  Dir.chdir "ext/fast_uri" do
    target = "parser.c"
    File.unlink(target) if File.exist?(target)
    sh "ragel parser.rl -o #{target}"
    raise "ragel failed" unless File.exist?(target)
  end
end

task graph: :ragel do
  Dir.chdir "ext/fast_uri" do
    sh "rm -f doc/graph.png"
    sh "ragel -Vp parser.rl -o parser.dot"
    sh "dot parser.dot -Tpng -o ../../doc/parser.png"
    sh "rm parser.dot"
    sh "open ../../doc/parser.png"
  end
end
