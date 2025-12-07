# frozen_string_literal: true

require "open3"
require "tempfile"

module AncientRuby
  module Runner
    class << self
      # Path to the bundled Ruby 0.49 binary
      def binary_path
        @binary_path ||= File.expand_path("../../exe/ruby-0.49.com", __dir__)
      end

      # Evaluate a string of Ruby 0.49 code
      def eval(code)
        Tempfile.create(["ancient_ruby", ".rb"]) do |file|
          file.write(code)
          file.flush
          execute(file.path)
        end
      end

      # Evaluate a Ruby 0.49 script file
      def eval_file(path, *args)
        raise Errno::ENOENT, "No such file: #{path}" unless File.exist?(path)

        execute(path, *args)
      end

      # Get Ruby 0.49 version
      def version
        stdout, _stderr, status = Open3.capture3(binary_path, "-v")
        raise ExecutionError, "Failed to get version" unless status.success?

        stdout.strip
      end

      private

      def execute(script_path, *args)
        ensure_binary_executable!

        cmd = [binary_path, script_path, *args]
        stdout, stderr, status = Open3.capture3(*cmd)

        unless status.success?
          error_message = stderr.empty? ? stdout : stderr
          raise ExecutionError, "Ruby 0.49 execution failed: #{error_message}"
        end

        stdout
      end

      def ensure_binary_executable!
        return if File.executable?(binary_path)

        File.chmod(0o755, binary_path)
      end
    end
  end
end
