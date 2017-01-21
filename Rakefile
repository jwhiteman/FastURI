require "bundler/gem_tasks"

require "rake/testtask"

Rake::TestTask.new(:test) do |t|
  t.libs << "test"
  t.libs << "lib"
  t.test_files = FileList['test/**/*_test.rb']
end

require "rake/extensiontask"

task build: :compile

Rake::ExtensionTask.new("uri_parse") do |ext|
  ext.lib_dir = "lib/uri_parse"
end

task default: %i(clobber ragel compile test)

task :ragel do
  Dir.chdir "ext/uri_parse" do
    target = "parse_machine.c"
    File.unlink(target) if File.exist?(target)

    sh "rm -f doc/graph.png"
    sh "ragel parse_machine.rl -o #{target}"
    sh "ragel -Vp parse_machine.rl -o graph.dot"
    sh "dot graph.dot -Tpng -o ../../doc/graph.png"
    sh "rm graph.dot"
    sh "open ../../doc/graph.png"

    raise "ragel failed" unless File.exist?(target)
  end
end
