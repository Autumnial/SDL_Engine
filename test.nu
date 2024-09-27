 ls | where type == file and name =~ "Test-" | each {|f| ^$'./($f.name)'}
