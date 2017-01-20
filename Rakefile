require "bundler/gem_tasks"

require "rspec/core/rake_task"

RSpec::Core::RakeTask.new(:spec)

require "rake/extensiontask"

task build: :compile

Rake::ExtensionTask.new("url_parse") do |ext|
  ext.lib_dir = "lib/url_parse"
end

task default: %i(clobber ragel compile spec)

task :ragel do
  Dir.chdir "ext/url_parse" do
    target = "parse_machine.c"
    File.unlink(target) if File.exist?(target)

    sh "ragel parse_machine.rl -o #{target}"

    raise "ragel failed" unless File.exist?(target)
  end
end
