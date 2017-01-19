require "bundler/gem_tasks"
require "rake/testtask"

Rake::TestTask.new(:test) do |t|
  t.libs << "test"
  t.libs << "lib"
  t.test_files = FileList['test/**/*_test.rb']
end

require "rake/extensiontask"

task build: :compile

Rake::ExtensionTask.new("url_parse") do |ext|
  ext.lib_dir = "lib/url_parse"
end

task default: %i(clobber ragel compile test)

task :ragel do
  Dir.chdir "ext/url_parse" do
    target = "parse_machine.c"
    File.unlink(target) if File.exist?(target)

    sh "ragel parse_machine.rl -o #{target}"

    raise "ragel failed" unless File.exist?(target)
  end
end
