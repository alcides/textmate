require 'tempfile'

# Use the same executable selection as Run, without saving or running the program.
executable = ENV['TM_AEON']
if executable.nil? || executable.empty?
  managed = File.expand_path('~/Library/Application Support/TextMate/LSP/Aeon/bin/aeon')
  executable = File.executable?(managed) ? managed : 'aeon'
end

source = Tempfile.new('textmate-format-')
output = Tempfile.new('textmate-format-output-')
errors = Tempfile.new('textmate-format-errors-')
begin
  source.write(STDIN.read)
  source.flush
  pid = fork do
    STDIN.reopen('/dev/null')
    STDOUT.reopen(output.path, 'w')
    STDERR.reopen(errors.path, 'w')
    directory = ENV['TM_DIRECTORY']
    Dir.chdir(directory) if directory && File.directory?(directory)
    begin
      exec executable, '--format', source.path
    rescue SystemCallError => error
      STDERR.puts("Cannot start Aeon: #{error.message}. Set TM_AEON or use Start Aeon to install it.")
      STDERR.flush
      exit! 127
    end
  end
  Process.waitpid(pid)
  success = $?.success?
  formatted = File.read(output.path)
  if !success || formatted.strip.empty?
    message = File.read(errors.path) + formatted
    puts(message.strip.empty? ? 'Aeon could not format this document.' : message)
    exit 206 # TextMate tooltip; never replace the buffer on failure.
  end
  STDOUT.write(formatted)
ensure
  source.close!
  output.close!
  errors.close!
end
