# Run with system Ruby; the bundle itself remains compatible with ruby18.
require 'open3'
require 'rbconfig'
script = File.expand_path('../Applications/TextMate/support/Bundles/Aeon.tmbundle/Support/format.rb', File.dirname(__FILE__))
source = "def main(args:Int):Unit := print \"Olá 🌍\"\n"
out, err, status = Open3.capture3(RbConfig.ruby, script, :stdin_data => source)
raise "Real Aeon failed: #{err}#{out}" unless status.success? && out.include?('args : Int') && out.include?('Olá 🌍')
out, err, status = Open3.capture3(RbConfig.ruby, script, :stdin_data => 'def INVALID (((')
raise 'Invalid input must produce a tooltip, not replacement text' unless status.exitstatus == 206 && !out.empty?
out, err, status = Open3.capture3({'TM_AEON' => '/nonexistent/textmate-aeon'}, RbConfig.ruby, script, :stdin_data => source)
raise "Missing executable was not handled: #{err}" unless status.exitstatus == 206 && out.include?('Cannot start Aeon')
puts 'PASS real formatting, Unicode, invalid input, missing executable'
